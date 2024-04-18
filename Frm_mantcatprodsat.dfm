object Form_mantcatprodsat: TForm_mantcatprodsat
  Left = 240
  Top = 208
  Width = 752
  Height = 356
  Caption = 'Mantenimiento de Tipos de Venta'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefaultPosOnly
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 736
    Height = 54
    ButtonHeight = 49
    Caption = 'ToolBar1'
    Images = dm.ImageList1
    TabOrder = 0
    object SpeedButton10: TSpeedButton
      Left = 0
      Top = 2
      Width = 49
      Height = 49
      Action = nuevo
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF0000FF
        FF0000FFFF00FF00FF007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF007B7B
        7B007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF00FF00FF00FF00FF00FF00
        FF0000FFFF000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF0000FFFF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF00FF00FF00FF00FF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF0000FFFF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000FFFF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF0000FF
        FF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00}
      Layout = blGlyphTop
    end
    object SpeedButton9: TSpeedButton
      Left = 49
      Top = 2
      Width = 49
      Height = 49
      Action = modifica
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        0000FF00FF000000000000000000000000000000000000000000FFFFFF00FFFF
        FF0000000000FFFFFF000000000000000000FFFFFF0000000000FFFF00000000
        00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF000000000000000000FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
        00000000000000FFFF0000000000FFFFFF00FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000000000000000000000000000000000000000000000
        000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        00000000000000FFFF00FFFFFF0000FFFF00000000000000000000FFFF000000
        0000FFFFFF00FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000000000000000000000000000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFFFF000000
        000000000000FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000FFFF000000000000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00
        FF00000000000000FF0000000000FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton8: TSpeedButton
      Left = 98
      Top = 2
      Width = 49
      Height = 49
      Action = borra
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF007B7B7B007B7B
        7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B00FF00FF007B7B7B00FF00
        FF00FF00FF000000FF000000FF000000FF00FF00FF007B7B7B00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00000000000084840000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00
        FF00FF00FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF000000000000FF
        FF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000000000FFFFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF0000FFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000000000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000FFFF000000000000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF0000000000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00000000000000000000FFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFF0000FFFF0000FFFF00000000000000FFFF00FFFFFF0000FFFF000000
        000000FFFF000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        000000000000FFFF0000FFFF0000FFFF00000000000000FFFF00FFFFFF0000FF
        FF00FFFFFF000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        00000000000000000000FFFF0000FFFF0000FFFF000000000000000000000000
        0000000000000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        0000000000000000000000000000FFFF000000000000FF00FF00FF00FF00FF00
        FF00FF00FF0000000000BDBDBD0000000000FF00FF00FF00FF00FF00FF000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton5: TSpeedButton
      Left = 147
      Top = 2
      Width = 49
      Height = 49
      Action = WindowClose1
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000000084000000840000FFFF0000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400000084000000840000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400000084000000840000FFFF000000000000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400FFFF0000000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400FFFF0000FFFF00000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object ToolButton3: TToolButton
      Left = 196
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 5
      Style = tbsSeparator
    end
  end
  object pge_catprod: TPageControl
    Left = 0
    Top = 54
    Width = 736
    Height = 263
    ActivePage = tbs_productos
    Align = alClient
    TabOrder = 1
    OnChange = pge_catprodChange
    object tbs_productos: TTabSheet
      Caption = 'Productos'
      object dbgrd_catprodsat: TdxDBGrid
        Left = 0
        Top = 0
        Width = 728
        Height = 235
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDPROD'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        OnKeyDown = dbgrd_catprodsatKeyDown
        DataSource = dts_catprodsat
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_catprodsatCustomDrawCell
        object dbgrd_catprodsatCODIGO: TdxDBGridMaskColumn
          Caption = 'Código'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'CODIGO'
        end
        object dbgrd_catprodsatDESCRI: TdxDBGridMaskColumn
          Caption = 'Descripción'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DESCRI'
        end
        object dbgrd_catprodsatSTATUS: TdxDBGridMaskColumn
          Caption = 'Status'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'STATUS'
        end
        object dbgrd_catprodsatFECBAJ: TdxDBGridDateColumn
          Caption = 'Baja'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECBAJ'
        end
      end
    end
    object tbs_usocfdi: TTabSheet
      Caption = 'Uso CFDI'
      ImageIndex = 1
      object dbgrd_usocfdi: TdxDBGrid
        Left = 0
        Top = 0
        Width = 728
        Height = 235
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'idusocfdi'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        OnKeyDown = dbgrd_catprodsatKeyDown
        DataSource = dts_usocfdi
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_catprodsatCustomDrawCell
        object dbgrd_usocfdiCODIGO: TdxDBGridMaskColumn
          Caption = 'Código'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'CODIGO'
        end
        object dbgrd_usocfdiDESCRI: TdxDBGridMaskColumn
          Caption = 'Descripción'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DESCRI'
        end
        object dbgrd_usocfdiSTATUS: TdxDBGridMaskColumn
          Caption = 'Status'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'STATUS'
        end
        object dbgrd_usocfdiFECBAJ: TdxDBGridDateColumn
          Caption = 'Baja'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECBAJ'
        end
      end
    end
    object tbs_regimen: TTabSheet
      Caption = 'Régimen Fiscal'
      ImageIndex = 2
      object dbgrd_regimen: TdxDBGrid
        Left = 0
        Top = 0
        Width = 728
        Height = 235
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDREGIMEN'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        TabOrder = 0
        OnKeyDown = dbgrd_catprodsatKeyDown
        DataSource = dts_regimen
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_catprodsatCustomDrawCell
        object dxDBGridMaskColumn1: TdxDBGridMaskColumn
          Caption = 'Código'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'CODIGO'
        end
        object dxDBGridMaskColumn2: TdxDBGridMaskColumn
          Caption = 'Descripción'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DESCRI'
        end
        object dxDBGridMaskColumn3: TdxDBGridMaskColumn
          Caption = 'Status'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'STATUS'
        end
        object dxDBGridDateColumn1: TdxDBGridDateColumn
          Caption = 'Baja'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECBAJ'
        end
      end
    end
  end
  object qry_catprodsat: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from inv_catprodsat'
      'order by codigo'
      ' '
      ' '
      ' ')
    UpdateObject = uqry_promot
    Left = 72
    Top = 168
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 16
    Top = 160
    object nuevo: TAction
      Caption = '&Nuevo'
      ImageIndex = 0
      ShortCut = 16462
      OnExecute = nuevoExecute
    end
    object modifica: TAction
      Caption = '&Modifica'
      Hint = 'Modifica'
      ImageIndex = 1
      ShortCut = 16461
      OnExecute = modificaExecute
    end
    object borra: TAction
      Caption = 'Borra'
      Hint = 'Borra'
      ImageIndex = 2
      ShortCut = 16450
      OnExecute = borraExecute
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
      Caption = '&Salir'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'Primero'
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
    object importar: TAction
      Caption = 'Importar'
      ImageIndex = 19
      OnExecute = importarExecute
    end
  end
  object uqry_promot: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_catprodsat'
      'set'
      '  IDPROD = :IDPROD,'
      '  CODIGO = :CODIGO,'
      '  DESCRI = :DESCRI,'
      '  STATUS = :STATUS,'
      '  FECBAJ = :FECBAJ'
      'where'
      '  IDPROD = :OLD_IDPROD')
    InsertSQL.Strings = (
      'insert into inv_catprodsat'
      '  (IDPROD, CODIGO, DESCRI, STATUS, FECBAJ)'
      'values'
      '  (:IDPROD, :CODIGO, :DESCRI, :STATUS, :FECBAJ)')
    DeleteSQL.Strings = (
      'delete from inv_catprodsat'
      'where'
      '  IDPROD = :OLD_IDPROD')
    Left = 72
    Top = 200
  end
  object dts_catprodsat: TDataSource
    AutoEdit = False
    DataSet = qry_catprodsat
    Left = 70
    Top = 232
  end
  object qry_usocfdi: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from inv_catusocfdisat'
      'order by codigo'
      ''
      ' '
      ' ')
    UpdateObject = uqry_usocfdi
    Left = 104
    Top = 168
  end
  object uqry_usocfdi: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_catusocfdisat'
      'set'
      '  DESCRI = :DESCRI,'
      '  STATUS = :STATUS,'
      '  FECBAJ = :FECBAJ'
      'where'
      '  IDUSOCFDI = :OLD_IDUSOCFDI')
    InsertSQL.Strings = (
      'insert into inv_catusocfdisat'
      '  (IDUSOCFDI, CODIGO, DESCRI, STATUS, FECBAJ)'
      'values'
      '  (:IDUSOCFDI, :CODIGO, :DESCRI, :STATUS, :FECBAJ)')
    DeleteSQL.Strings = (
      'delete from inv_catusocfdisat'
      'where'
      '  IDUSOCFDI = :OLD_IDUSOCFDI')
    Left = 104
    Top = 200
  end
  object dts_usocfdi: TDataSource
    AutoEdit = False
    DataSet = qry_usocfdi
    Left = 102
    Top = 232
  end
  object qry_regimen: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from inv_regimenfiscal'
      'order by codigo'
      ' ')
    UpdateObject = uqry_regimen
    Left = 136
    Top = 168
  end
  object uqry_regimen: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_regimenfiscal'
      'set'
      '  DESCRI = :DESCRI,'
      '  STATUS = :STATUS,'
      '  FECBAJ = :FECBAJ'
      'where'
      '  IDREGIMEN = :OLD_IDREGIMEN')
    InsertSQL.Strings = (
      'insert into inv_regimenfiscal'
      '  (IDREGIMEN, CODIGO, DESCRI, STATUS, FECBAJ)'
      'values'
      '  (:IDREGIMEN, :CODIGO, :DESCRI, :STATUS, :FECBAJ)')
    DeleteSQL.Strings = (
      'delete from inv_regimenfiscal'
      'where'
      '  IDREGIMEN = :OLD_IDREGIMEN')
    Left = 136
    Top = 200
  end
  object dts_regimen: TDataSource
    AutoEdit = False
    DataSet = qry_regimen
    Left = 134
    Top = 232
  end
end
