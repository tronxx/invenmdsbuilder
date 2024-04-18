object Form_infent: TForm_infent
  Left = 220
  Top = 174
  Width = 803
  Height = 474
  Caption = 'Informe de Compras'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 795
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object btn_imprel: TBitBtn
      Left = 451
      Top = 9
      Width = 77
      Height = 25
      Action = generar_reporte
      Caption = 'Reporte'
      TabOrder = 0
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000FF00FF0000000000BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF000000000000000000BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000000000000000000000FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF000000000000000000BFBF
        BF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBF
        BF00FFFFFF00BFBFBF00FFFFFF000000FF00FFFFFF000000000000000000FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
        FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000BFBFBF00FFFFFF0000000000FFFF
        FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
    end
    object pnl_datos: TGroupBox
      Left = 0
      Top = 0
      Width = 433
      Height = 41
      Align = alLeft
      Caption = 'Fecha:'
      TabOrder = 1
      object lbl_vigencia: TLabel
        Left = 35
        Top = 18
        Width = 63
        Height = 13
        Caption = 'Fecha Inicial:'
      end
      object lbl_corte: TLabel
        Left = 232
        Top = 19
        Width = 58
        Height = 13
        Caption = 'Fecha Final:'
      end
      object date_ini: TDateTimePicker
        Left = 100
        Top = 14
        Width = 89
        Height = 22
        CalAlignment = dtaLeft
        Date = 38762.7111857986
        Time = 38762.7111857986
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object date_fin: TDateTimePicker
        Left = 294
        Top = 14
        Width = 92
        Height = 22
        CalAlignment = dtaLeft
        Date = 38982.3491966782
        Time = 38982.3491966782
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 41
    Width = 795
    Height = 399
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'PROVE'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 1
    DataSource = dts_llenar
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrd_renglonesPROVE: TdxDBGridMaskColumn
      Caption = 'Proveedor'
      Width = 113
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PROVE'
    end
    object dbgrd_renglonesNOMBRE: TdxDBGridMaskColumn
      Caption = 'Nombre'
      Width = 262
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMBRE'
    end
    object dbgrd_renglonesCOMPRASI: TdxDBGridCurrencyColumn
      Caption = 'Compra SI'
      Width = 109
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COMPRASI'
    end
    object dbgrd_renglonesCOMPRANO: TdxDBGridCurrencyColumn
      Caption = 'Compra NO'
      Width = 90
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COMPRANO'
    end
    object dbgrd_renglonesCOMPRAMES: TdxDBGridCurrencyColumn
      Caption = 'Compra Mes'
      Width = 89
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COMPRAMES'
    end
    object dbgrd_renglonesRANK1: TdxDBGridMaskColumn
      Caption = 'Pos'
      Width = 40
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RANK1'
    end
    object dbgrd_renglonesCOMPRANU: TdxDBGridCurrencyColumn
      Caption = 'Compra Añio'
      Width = 93
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COMPRANU'
    end
    object dbgrd_renglonesRANK2: TdxDBGridMaskColumn
      Caption = 'Pos'
      Width = 53
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RANK2'
    end
    object dbgrd_renglonesTOTGRAL: TdxDBGridCurrencyColumn
      Caption = 'Total Gral.'
      Width = 90
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TOTGRAL'
    end
    object dbgrd_renglonesRANK3: TdxDBGridMaskColumn
      Caption = 'Pos'
      Width = 46
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RANK3'
    end
  end
  object qry_delete: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'delete from infent')
    Left = 88
    Top = 136
  end
  object qry_proves: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select unique prove from entradas where tipo= :TPENT and'
      #9'fecha between :FECREL and :FECFIN and cia= :CIA order by prove')
    Left = 88
    Top = 169
    ParamData = <
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_compra: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select sum(importe+iva) as si from entradas where tipo= :TPENT a' +
        'nd prove= :PROVE'
      
        #9'and fecha between :FECINI and :FECFIN and coniva= :SINO and cia' +
        '= :CIA'
      '')
    Left = 88
    Top = 207
    ParamData = <
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PROVE'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SINO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_companio: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select sum(importe+iva) as anio from entradas where tipo= :TPENT' +
        ' and prove= :PROVE'
      #9'and fecha < :FECINI and fecha >= :FECINIANU and cia= :CIA'
      ''
      ''
      ' '
      ' ')
    Left = 88
    Top = 243
    ParamData = <
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PROVE'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECINIANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_infent: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from infent')
    UpdateObject = uqry_infent
    Left = 88
    Top = 278
  end
  object uqry_infent: TUpdateSQL
    ModifySQL.Strings = (
      'update infent'
      'set'
      '  PROVE = :PROVE,'
      '  COMPRASI = :COMPRASI,'
      '  COMPRANO = :COMPRANO,'
      '  COMPRAMES = :COMPRAMES,'
      '  RANK1 = :RANK1,'
      '  COMPRANU = :COMPRANU,'
      '  RANK2 = :RANK2,'
      '  TOTGRAL = :TOTGRAL,'
      '  RANK3 = :RANK3'
      'where'
      '  PROVE = :OLD_PROVE')
    InsertSQL.Strings = (
      'insert into infent'
      
        '  (PROVE, COMPRASI, COMPRANO, COMPRAMES, RANK1, COMPRANU, RANK2,' +
        ' TOTGRAL, '
      '   RANK3)'
      'values'
      
        '  (:PROVE, :COMPRASI, :COMPRANO, :COMPRAMES, :RANK1, :COMPRANU, ' +
        ':RANK2, '
      '   :TOTGRAL, :RANK3)')
    DeleteSQL.Strings = (
      'delete from infent'
      'where'
      '  PROVE = :OLD_PROVE')
    Left = 122
    Top = 279
  end
  object qry_nomprov: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select nombre from proveedor where codigo = :PROVE')
    Left = 121
    Top = 169
    ParamData = <
      item
        DataType = ftString
        Name = 'PROVE'
        ParamType = ptUnknown
      end>
  end
  object qry_llenar: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select a.*,b.nombre from infent a join proveedor b on b.codigo =' +
        ' a.prove')
    Left = 122
    Top = 136
  end
  object dts_llenar: TDataSource
    DataSet = qry_llenar
    Left = 153
    Top = 137
  end
  object qry_compmes: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as mes'
      '        from entradas b join renentra a'
      '        on b.alm=a.alm and b.numero=a.numero and b.cia=a.cia'
      '        and b.tipo=a.tipo'
      '        join inven c on a.codinv = c.codigo and a.cia = c.cia'
      
        '        where b.fecha between :FECINI and :FECFIN and b.tipo= :T' +
        'PENT'
      #9'and b.cia= :CIA'
      '        and c.linea = :LINEA'
      '')
    Left = 305
    Top = 135
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end>
  end
  object qry_companu: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as anual'
      '        from entradas b join renentra a'
      '        on b.alm=a.alm and b.numero=a.numero and b.cia=a.cia'
      '        and b.tipo=a.tipo'
      '        where'
      
        '        b.fecha < :FECINI and fecha >= :FECREAL and b.tipo= :TPE' +
        'NT and a.codinv=  :CODINV and b.cia= :CIA')
    Left = 306
    Top = 167
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECREAL'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODINV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_totmes: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as totmes'
      '        from entradas b join renentra a'
      '        on b.alm=a.alm and b.numero=a.numero and b.cia=a.cia'
      '        and b.tipo=a.tipo'
      
        '        where b.fecha between :FECINI and :FECFIN and b.tipo= :T' +
        'PENT and b.cia= :CIA')
    Left = 306
    Top = 201
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_totanual: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as  totanu'
      '        from entradas b join renentra a'
      '        on b.alm=a.alm and b.numero=a.numero and b.cia=a.cia'
      '        and b.tipo=a.tipo'
      '        where'
      
        '        b.fecha between :FECINI and :FECFIN and b.tipo= :TPENT a' +
        'nd b.cia= :CIA'
      ''
      ' '
      ' ')
    Left = 306
    Top = 234
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_lineacod: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select c.linea, d.orden, sum(a.importe*((a.piva/100)+1)) as mes'
      '        from entradas b join renentra a'
      '        on b.alm=a.alm and b.numero=a.numero and b.cia=a.cia'
      '        and b.tipo=a.tipo'
      '        join inven c on a.codinv = c.codigo and a.cia = c.cia'
      '        join lineas d on c.linea = d.numero and c.cia = d.cia'
      '        where b.fecha between :FECINI and :FECFIN'
      '        and ( b.tipo= :TPENT or b.tipo= :TPDEV)'
      #9'and b.cia= :CIA'
      '        group by c.linea, d.orden'
      '')
    Left = 269
    Top = 186
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_devol: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as devol'
      #9'from entradas b join renentra a'
      '        on b.alm=a.alm and b.numero=a.numero and b.cia=a.cia'
      '        and b.tipo=a.tipo'
      '        where'
      
        #9'b.fecha between  :FECINI and :FECFIN  and b.tipo= :TPDEV and a.' +
        'codinv= :CODINV and b.cia= :CIA')
    Left = 338
    Top = 153
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODINV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_totdevmes: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as totdevmes'
      #9'from entradas b join renentra a'
      '        on b.alm=a.alm and b.numero=a.numero and b.cia=a.cia'
      '        and b.tipo=a.tipo'
      '        where'
      
        #9'b.fecha between  :FECINI and :FECFIN  and b.tipo= :TPDEV and b.' +
        'cia= :CIA')
    Left = 373
    Top = 153
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 544
    Top = 224
    object exportar: TAction
      Caption = 'Expotar a...'
      ImageIndex = 9
      OnExecute = exportarExecute
    end
    object generar_reporte: TAction
      Caption = 'Reporte'
      ImageIndex = 21
      OnExecute = generar_reporteExecute
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 432
    Top = 256
    object Expotara1: TMenuItem
      Action = exportar
    end
  end
end
