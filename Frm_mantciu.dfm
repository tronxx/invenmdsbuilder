object Form_mantciu: TForm_mantciu
  Left = 281
  Top = 223
  Width = 527
  Height = 327
  HelpContext = 30
  Caption = 'Mantenimiento de Poblaciones'
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
    Width = 511
    Height = 51
    ButtonHeight = 47
    Caption = 'ToolBar1'
    Images = dm.ImageList1
    TabOrder = 0
    object SpeedButton3: TSpeedButton
      Left = 0
      Top = 2
      Width = 60
      Height = 47
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
    object SpeedButton1: TSpeedButton
      Left = 60
      Top = 2
      Width = 60
      Height = 47
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
    object SpeedButton4: TSpeedButton
      Left = 120
      Top = 2
      Width = 60
      Height = 47
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
    object ToolButton3: TToolButton
      Left = 180
      Top = 2
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object SpeedButton5: TSpeedButton
      Left = 188
      Top = 2
      Width = 60
      Height = 47
      Action = exporta
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
      Layout = blGlyphTop
    end
    object SpeedButton2: TSpeedButton
      Left = 248
      Top = 2
      Width = 60
      Height = 47
      Action = importa
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00000000000000
        0000FFFFFF00000000000000000000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF0000000000FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000FF0000000000FF00FF0000000000FFFFFF0000000000BFBF
        BF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000FF000000FF000000000000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        FF000000FF000000FF000000FF000000FF0000000000FFFFFF00000000000000
        0000FFFFFF000000000000000000000000000000000000000000000000000000
        FF000000FF000000FF000000FF000000FF000000FF0000000000FFFFFF00FFFF
        FF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00FF00000000000000
        FF000000FF000000FF000000FF000000FF000000FF000000FF0000000000BFBF
        BF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00000000000000
        FF000000FF000000FF000000FF000000FF000000FF0000000000FFFFFF00FFFF
        FF00FFFFFF000000000000000000FF00FF00FF00FF00FF00FF00000000000000
        FF000000FF000000FF000000FF000000FF000000000000000000000000000000
        00000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000FF000000FF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton8: TSpeedButton
      Left = 308
      Top = 2
      Width = 60
      Height = 47
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
  end
  object dbgrd_ciudades: TdxDBGrid
    Left = 0
    Top = 51
    Width = 511
    Height = 238
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'NUMERO'
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    TabOrder = 1
    OnKeyDown = dbgrd_ciudadesKeyDown
    DataSource = dts_ciudades
    Filter.Criteria = {00000000}
    OptionsBehavior = [edgoAutoSearch, edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseLocate]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrd_ciudadesCIUDAD: TdxDBGridMaskColumn
      Caption = 'Ciudad'
      Width = 275
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMBRE'
    end
    object dbgrd_ciudadesESTADO: TdxDBGridMaskColumn
      Caption = 'Estado'
      Visible = False
      Width = 240
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ESTADO'
    end
    object dbgrd_ciudadesSTATUS: TdxDBGridMaskColumn
      Caption = 'Status'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'STATUS'
    end
    object dbgrd_ciudadesFECBAJ: TdxDBGridDateColumn
      Caption = 'Baja'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'FECBAJ'
    end
  end
  object qry_ciudades: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.nombre, a.numero, b.idestado, b.nombre as estado,'
      'a.status, a.fecbaj'
      'from poblacs a join car_relpobs c on a.numero = c.iddato1 '
      'join car_estados b on c.iddato2 = b.idestado'
      'where c.tiporel = :TIPOREL'
      'order by b.nombre, a.nombre'
      ' '
      ' ')
    UpdateObject = uqry_poblacs
    Left = 312
    Top = 32
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPOREL'
        ParamType = ptUnknown
      end>
  end
  object uqry_poblacs: TUpdateSQL
    ModifySQL.Strings = (
      'update poblacs'
      'set'
      '  NOMBRE = :NOMBRE,'
      '  STATUS = :STATUS,'
      '  FECBAJ = :FECBAJ'
      'where'
      '  NUMERO = :OLD_NUMERO')
    InsertSQL.Strings = (
      'insert into poblacs'
      '  (NOMBRE, NUMERO, STATUS, FECBAJ)'
      'values'
      '  (:NOMBRE, :NUMERO, :STATUS, :FECBAJ)')
    DeleteSQL.Strings = (
      'delete from poblacs'
      'where'
      '  NUMERO = :OLD_NUMERO')
    Left = 342
    Top = 32
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 280
    Top = 32
    object nuevo: TAction
      Caption = '&Nuevo'
      Hint = 'Nuevo'
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
      Hint = 'Graba'
      ImageIndex = 9
      ShortCut = 16455
      OnExecute = grabarExecute
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      Enabled = False
      Hint = 'Cancelar'
      ImageIndex = 11
      ShortCut = 16460
      OnExecute = cancelarExecute
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = 'C&lose'
      Hint = 'S a l i r'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'primero'
      Hint = 'Selecciona la Primera Poblacion'
      ImageIndex = 5
      ShortCut = 49232
    end
    object anterior: TAction
      Caption = 'Anterior'
      Hint = 'Selecciona la Anterior Poblacion'
      ImageIndex = 6
      ShortCut = 49217
    end
    object siguiente: TAction
      Caption = 'Siguiente'
      Hint = 'Selecciona la Siguiente Poblacion'
      ImageIndex = 8
      ShortCut = 49235
    end
    object ultimo: TAction
      Caption = 'Ultimo'
      Hint = 'Selecciona la Ultima Poblacion'
      ImageIndex = 7
      ShortCut = 49237
    end
    object exporta: TAction
      Caption = 'Exportar'
      Hint = 'Exporta los datos'
      ImageIndex = 19
      OnExecute = exportaExecute
    end
    object importa: TAction
      Caption = 'Importa'
      Hint = 'Importa los datos'
      ImageIndex = 27
      OnExecute = importaExecute
    end
  end
  object dts_ciudades: TDataSource
    AutoEdit = False
    DataSet = qry_ciudades
    Left = 446
    Top = 32
  end
  object qry_modif: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from ciudades order by nombre'
      '')
    Left = 312
    Top = 64
  end
  object qry_inserta: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from ciudades order by nombre'
      '')
    Left = 312
    Top = 96
  end
  object qry_borra: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from ciudades order by nombre'
      '')
    Left = 312
    Top = 128
  end
  object qry_estado: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select * from car_estados where tipo = :TIPO and nombre = :NOMBR' +
        'E')
    UpdateObject = uqry_estado
    Left = 312
    Top = 160
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'NOMBRE'
        ParamType = ptUnknown
      end>
  end
  object qry_carrelpob: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from car_relpobs where idrelpob = :IDRELPOB'
      'or ( tiporel = :TIPOREL and iddato1 = :IDDATO1)'
      ' ')
    UpdateObject = uqry_carrelpob
    Left = 312
    Top = 192
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDRELPOB'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDDATO1'
        ParamType = ptUnknown
      end>
  end
  object uqry_carrelpob: TUpdateSQL
    ModifySQL.Strings = (
      'update car_relpobs'
      'set'
      '  IDRELPOB = :IDRELPOB,'
      '  TIPOREL = :TIPOREL,'
      '  IDDATO1 = :IDDATO1,'
      '  IDDATO2 = :IDDATO2'
      'where'
      '  IDRELPOB = :OLD_IDRELPOB')
    InsertSQL.Strings = (
      'insert into car_relpobs'
      '  (IDRELPOB, TIPOREL, IDDATO1, IDDATO2)'
      'values'
      '  (:IDRELPOB, :TIPOREL, :IDDATO1, :IDDATO2)')
    DeleteSQL.Strings = (
      'delete from car_relpobs'
      'where'
      '  IDRELPOB = :OLD_IDRELPOB')
    Left = 342
    Top = 192
  end
  object uqry_estado: TUpdateSQL
    ModifySQL.Strings = (
      'update car_estados'
      'set'
      '  IDESTADO = :IDESTADO,'
      '  TIPO = :TIPO,'
      '  NOMBRE = :NOMBRE'
      'where'
      '  IDESTADO = :OLD_IDESTADO')
    InsertSQL.Strings = (
      'insert into car_estados'
      '  (IDESTADO, TIPO, NOMBRE)'
      'values'
      '  (:IDESTADO, :TIPO, :NOMBRE)')
    DeleteSQL.Strings = (
      'delete from car_estados'
      'where'
      '  IDESTADO = :OLD_IDESTADO')
    Left = 342
    Top = 160
  end
end
