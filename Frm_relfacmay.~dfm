object Form_relfacmay: TForm_relfacmay
  Left = 286
  Top = 329
  Width = 648
  Height = 299
  Caption = 'Relación de Documentos Mayoreo x Fecha Vencimiento'
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
    Width = 640
    Height = 65
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 3
      Top = 16
      Width = 77
      Height = 13
      Caption = 'Primer Mayorista'
    end
    object Label2: TLabel
      Left = 3
      Top = 40
      Width = 77
      Height = 13
      Caption = 'Ultimo Mayorista'
    end
    object Label3: TLabel
      Left = 147
      Top = 16
      Width = 88
      Height = 13
      Caption = 'Vencimiento Inicial'
    end
    object Label4: TLabel
      Left = 147
      Top = 40
      Width = 83
      Height = 13
      Caption = 'Vencimiento Final'
    end
    object edt_prmay: TEdit
      Left = 83
      Top = 11
      Width = 54
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 0
    end
    object edt_ulmay: TEdit
      Left = 83
      Top = 35
      Width = 54
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 1
      Text = 'ZZ'
    end
    object date_fecini: TDateTimePicker
      Left = 248
      Top = 11
      Width = 100
      Height = 21
      CalAlignment = dtaLeft
      Date = 40011.5148243981
      Time = 40011.5148243981
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 2
    end
    object date_fecfin: TDateTimePicker
      Left = 248
      Top = 35
      Width = 100
      Height = 21
      CalAlignment = dtaLeft
      Date = 40011.5148243981
      Time = 40011.5148243981
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 3
    end
    object BitBtn1: TBitBtn
      Left = 368
      Top = 16
      Width = 75
      Height = 25
      TabOrder = 4
      OnClick = BitBtn1Click
      Kind = bkOK
    end
    object BitBtn2: TBitBtn
      Left = 464
      Top = 16
      Width = 105
      Height = 25
      Action = exportar
      Caption = 'Exportar a...'
      TabOrder = 5
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000FF000000FF0000000000FF00FF00FF00FF00FF00FF00000000000000
        0000000000000000000000000000000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF0000000000FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF0000000000FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000FF000000000000000000FFFF
        FF000000000000000000FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF0000000000FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00000000000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF0000000000FF00FF00FF00FF0000000000FFFF
        FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
        00000000FF000000FF0000000000FF00FF00FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
        00000000FF0000000000FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF000000000000000000FFFFFF00000000000000000000000000000000000000
        000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF0000000000BDBDBD00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
    end
  end
  object page_acum: TPageControl
    Left = 0
    Top = 65
    Width = 640
    Height = 204
    ActivePage = tbs_mensual
    Align = alClient
    TabOrder = 1
    object tbs_mensual: TTabSheet
      Caption = 'Mensual'
      object dbgrd_doctos: TdxDBGrid
        Left = 0
        Top = 0
        Width = 632
        Height = 176
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDMOV'
        ShowSummaryFooter = True
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        DataSource = dts_marcas
        Filter.Active = True
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        ShowRowFooter = True
        OnCustomDrawCell = dbgrd_doctosCustomDrawCell
        object dbgrd_doctosMAYORIS: TdxDBGridMaskColumn
          Caption = 'Codigo'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MAYORIS'
        end
        object dbgrd_doctosFECHA: TdxDBGridDateColumn
          Caption = 'Fecha'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHA'
        end
        object dbgrd_doctosDOCTO: TdxDBGridMaskColumn
          Caption = 'Factura'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DOCTO'
        end
        object dbgrd_doctosPAGARE: TdxDBGridMaskColumn
          Caption = 'Pagaré'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'PAGARE'
        end
        object dbgrd_doctosVENCE: TdxDBGridDateColumn
          Caption = 'Vence'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'VENCE'
        end
        object dbgrd_doctosCONCEP: TdxDBGridMaskColumn
          Caption = 'Concepto'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'CONCEP'
        end
        object dbgrd_doctosIMPORTE: TdxDBGridCurrencyColumn
          Caption = 'Importe'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'IMPORTE'
          SummaryFooterType = cstSum
          SummaryFooterField = 'IMPORTE'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_doctosSALDO: TdxDBGridCurrencyColumn
          Caption = 'Saldo'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SALDO'
          SummaryFooterType = cstSum
          SummaryFooterField = 'SALDO'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
      end
    end
    object tbs_anual: TTabSheet
      Caption = 'Anual'
      ImageIndex = 1
      object dbgrd_anual: TdxDBGrid
        Left = 0
        Top = 0
        Width = 632
        Height = 176
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'MAYORIS'
        ShowSummaryFooter = True
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        DataSource = dts_mayoris
        Filter.Active = True
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        ShowRowFooter = True
        OnCustomDrawCell = dbgrd_doctosCustomDrawCell
        object dbgrd_anualMAYORIS: TdxDBGridMaskColumn
          Caption = 'Mayorista'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MAYORIS'
        end
        object dbgrd_anualENE: TdxDBGridCurrencyColumn
          Caption = 'Enero'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ENE'
          SummaryFooterType = cstSum
          SummaryFooterField = 'ENE'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualFEB: TdxDBGridCurrencyColumn
          Caption = 'Febrero'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FEB'
          SummaryFooterType = cstSum
          SummaryFooterField = 'FEB'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualMAR: TdxDBGridCurrencyColumn
          Caption = 'Marzo'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MAR'
          SummaryFooterType = cstSum
          SummaryFooterField = 'MAR'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualABR: TdxDBGridCurrencyColumn
          Caption = 'Abril'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ABR'
          SummaryFooterType = cstSum
          SummaryFooterField = 'ABR'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualMAY: TdxDBGridCurrencyColumn
          Caption = 'Mayo'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MAY'
          SummaryFooterType = cstSum
          SummaryFooterField = 'MAY'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualJUN: TdxDBGridCurrencyColumn
          Caption = 'Junio'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'JUN'
          SummaryFooterType = cstSum
          SummaryFooterField = 'JUN'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualJUL: TdxDBGridCurrencyColumn
          Caption = 'Julio'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'JUL'
          SummaryFooterType = cstSum
          SummaryFooterField = 'JUL'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualAGO: TdxDBGridCurrencyColumn
          Caption = 'Agosto'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'AGO'
          SummaryFooterType = cstSum
          SummaryFooterField = 'AGO'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualSEP: TdxDBGridCurrencyColumn
          Caption = 'Septiembre'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SEP'
          SummaryFooterType = cstSum
          SummaryFooterField = 'SEP'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualOCT: TdxDBGridCurrencyColumn
          Caption = 'Octubre'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'OCT'
          SummaryFooterType = cstSum
          SummaryFooterField = 'OCT'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualNOV: TdxDBGridCurrencyColumn
          Caption = 'Noviembre'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'NOV'
          SummaryFooterType = cstSum
          SummaryFooterField = 'NOV'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualDIC: TdxDBGridCurrencyColumn
          Caption = 'Diciembre'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DIC'
          SummaryFooterType = cstSum
          SummaryFooterField = 'DIC'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
        object dbgrd_anualTOT: TdxDBGridCurrencyColumn
          Caption = 'Total'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TOT'
          SummaryFooterType = cstSum
          SummaryFooterField = 'TOT'
          SummaryFooterFormat = '$,0.00;-$,0.00'
        end
      end
    end
  end
  object qry_marcas: TQuery
    CachedUpdates = True
    AfterScroll = qry_marcasAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idmov, mayoris, fecha, docto, pagare, vence, concep, impo' +
        'rte, saldo'
      'from movmay2 '
      'where vence between :FECINI and :FECFIN'
      'and mayoris between :PRMAY and :ULMAY  and coa = '#39'C'#39
      'order by vence, mayoris, docto')
    Left = 312
    Top = 88
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
        Name = 'PRMAY'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ULMAY'
        ParamType = ptUnknown
      end>
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 280
    Top = 88
    object nuevo: TAction
      Caption = '&Nuevo'
      ImageIndex = 0
      ShortCut = 16462
    end
    object modifica: TAction
      Caption = '&Modifica'
      Hint = 'Modifica'
      ImageIndex = 1
      ShortCut = 16461
    end
    object borra: TAction
      Caption = 'Borra'
      Hint = 'Borra'
      ImageIndex = 2
      ShortCut = 16450
    end
    object grabar: TAction
      Caption = 'Grabar'
      Enabled = False
      ImageIndex = 9
      ShortCut = 16455
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      Enabled = False
      ImageIndex = 11
      ShortCut = 16460
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = 'C&lose'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'primero'
      Hint = 'Selecciona la Primer Marca'
      ImageIndex = 5
      ShortCut = 49232
    end
    object anterior: TAction
      Caption = 'Anterior'
      Hint = 'Selecciona la Anterior Marca'
      ImageIndex = 6
      ShortCut = 49217
    end
    object siguiente: TAction
      Caption = 'Siguiente'
      Hint = 'Selecciona la Siguiente Marca'
      ImageIndex = 8
      ShortCut = 49235
    end
    object ultimo: TAction
      Caption = 'Ultimo'
      Hint = 'Selecciona la Ultima Marca'
      ImageIndex = 7
      ShortCut = 49237
    end
    object exportar: TAction
      Caption = 'Exportar a...'
      ImageIndex = 19
      OnExecute = exportarExecute
    end
    object imprimir: TAction
      Caption = 'Imprimir'
      ImageIndex = 21
    end
  end
  object dts_marcas: TDataSource
    AutoEdit = False
    DataSet = qry_marcas
    Left = 374
    Top = 88
  end
  object qry_mayoris: TQuery
    CachedUpdates = True
    AfterScroll = qry_marcasAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select mayoris,'
      'sum(0) as ene,'
      'sum(0) as feb,'
      'sum(0) as mar,'
      'sum(0) as abr,'
      'sum(0) as may,'
      'sum(0) as jun,'
      'sum(0) as jul,'
      'sum(0) as ago,'
      'sum(0) as sep,'
      'sum(0) as oct,'
      'sum(0) as nov,'
      'sum(0) as dic,'
      'sum(0) as tot'
      'from movmay2'
      'where mayoris = '#39'-1'#39
      'group by mayoris'
      ' ')
    UpdateObject = UpdateSQL1
    Left = 312
    Top = 120
  end
  object UpdateSQL1: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_marcas'
      'set'
      '  MARCA = :MARCA'
      'where'
      '  IDMARCAINV = :OLD_IDMARCAINV')
    InsertSQL.Strings = (
      'insert into inv_marcas'
      '  (IDMARCAINV, CODIGO, MARCA)'
      'values'
      '  (:IDMARCAINV, :CODIGO, :MARCA)')
    DeleteSQL.Strings = (
      'delete from inv_marcas'
      'where'
      '  IDMARCAINV = :OLD_IDMARCAINV')
    Left = 342
    Top = 120
  end
  object dts_mayoris: TDataSource
    AutoEdit = False
    DataSet = qry_mayoris
    Left = 374
    Top = 120
  end
  object qry_meses: TQuery
    CachedUpdates = True
    AfterScroll = qry_marcasAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select mayoris, month(vence) as mesvence, sum(importe) as import' +
        'e'
      'from movmay2 '
      'where vence between :FECINI and :FECFIN'
      'and mayoris between :PRMAY and :ULMAY  and coa = '#39'C'#39
      'group by mayoris, mesvence')
    Left = 312
    Top = 152
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
        Name = 'PRMAY'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ULMAY'
        ParamType = ptUnknown
      end>
  end
end
